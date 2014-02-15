$(function() {
	var HIGHLIGHTED = /^sh_.*|console$/;
	var requestsStarted = 0;
	var checkRequests = function() { };
	$("pre").each(function() {
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
		var figure = document.createElement("figure");
		var ref = pre.getAttribute("data-source");
		$(figure).insertBefore(pre).append($("<figcaption/>")
			.append($("<a/>", { href: ref }).text(ref))).append(pre);
		if($(pre).hasClass("console"))
		{
			$(pre).removeClass("console");
			$(figure).addClass("console");
		}
		if(ref)
		{
			++requestsStarted;
			$.ajax({
				url: ref,
				success: function(content) {
					pre.textContent = content.replace(/^\t+/gm, function(r) {
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
			sh_highlightDocument();
	};
	
	checkRequests();
});
