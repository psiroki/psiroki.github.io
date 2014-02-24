$(function() {
	var HIGHLIGHTED = /^sh_.*|console$/;
	var requestsStarted = 0;
	var checkRequests = function() { };
	var storage = window.localStorage || { };
	$("pre, code").each(function() {
		var pre = this;
		var classes = this.className.split(/\s+/);
		var skip = true;
		for(var i=0; i<classes.length; ++i)
		{
			if(HIGHLIGHTED.test(classes[i]))
			{
				skip = false;
				break;
			}
		}
		if(skip)
			return;
		var ref = this.getAttribute("data-source");
		if(!$("pre").hasClass("inline") && this.nodeName.toLowerCase() != "code")
		{
			var figure = $("<figure/>");
			
			figure.insertBefore(pre).append(pre);
			
			if(ref) {
				figure.prepend($("<figcaption/>")
					.append($("<a/>", { href: ref }).text(ref)))
			}
			
			if($(pre).hasClass("console"))
			{
				$(pre).removeClass("console");
				figure.addClass("console");
			}
		}
		
		if(ref)
		{
			++requestsStarted;
			// add precached version
			if(ref in storage)
				pre.textContent = storage[ref];
			$.ajax({
				url: ref,
				success: function(content) {
					storage[ref] = pre.textContent = content.replace(/^\t+/gm, function(r) {
						var parts = [];
						for(var i=0; i<r.length; ++i)
							parts[i] = "    ";
						return parts.join("");
					});
				},
				complete: function() {
					--requestsStarted;
					checkRequests();
				}
			});
		}
	});
	
	checkRequests = function() {
		if(requestsStarted <= 0)
		{
			sh_highlightDocument();
			sh_highlightNodeList(document.getElementsByTagName("code"));
		}
	};
	
	checkRequests();
});
