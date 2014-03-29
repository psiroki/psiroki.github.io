$(function() {
	var HIGHLIGHTED = /^sh_.*|console$/;
	var requestsStarted = 0;
	var checkRequests = function() { };
	var storage = window.localStorage || { };
	
	function ContentProvider()
	{
		this._listeners = [ ];
		this._content = null;
	}
	
	ContentProvider.prototype.addListener = function(f) {
		if(this._content !== null)
			f.call(this, this._content);
		else
			this._listeners.push(f);
	};
	
	ContentProvider.prototype.setContent = function(content) {
		this._content = content;
		var listeners = this._listeners;
		for(var i=0; i<listeners.length; ++i)
		{
			var fun = listeners[i];
			fun.call(this, content);
		}
		
		this._listeners = [ ];
	};
	
	var contents = { };
	
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
			// add precached version
			if(ref in storage)
				pre.textContent = storage[ref];
			if(ref in contents)
			{
				contents[ref].addListener(function(content) {
					console.log("Provided content for ref:", ref);
					pre.textContent = content;
				});
			} else
			{
				contents[ref] = new ContentProvider();
				++requestsStarted;
				$.ajax({
					url: ref,
					success: function(content) {
						content = content.replace(/^\t+/gm, function(r) {
							var parts = [];
							for(var i=0; i<r.length; ++i)
								parts[i] = "    ";
							return parts.join("");
						});
						
						storage[ref] = pre.textContent = content;
						
						if(ref in contents)
							contents[ref].setContent(content);
					},
					complete: function() {
						--requestsStarted;
						checkRequests();
					}
				});
			}
		}
	});
	
	checkRequests = function() {
		if(requestsStarted <= 0)
		{
			sh_highlightDocument();
			if(document.querySelectorAll)
			{
				var nodes = document.querySelectorAll("td.sh_cpp");
				for(var i=0; i<nodes.length; ++i)
				{
					var n = nodes[i];
					n.className = n.className.replace(/\bsh_cpp\b/g, "");
					var code = document.createElement("code");
					code.className = "sh_cpp";
					n.insertBefore(code, n.firstChild);
					for(var c = code.nextSibling; c; c = code.nextSibling)
					{
						n.removeChild(c);
						code.appendChild(c);
					}
				}
			}
			sh_highlightNodeList(document.getElementsByTagName("code"));
		}
	};
	
	checkRequests();
});
