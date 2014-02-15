$(function() {
	var HIGHLIGHTED = /^sh_.*$/;
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
		var ref = data.getAttribute("data-source");
		if(ref)
		{
			++requestsStarted;
			$.ajax({
				url: ref,
				success: function(content) {
					pre.textContent = content;
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
