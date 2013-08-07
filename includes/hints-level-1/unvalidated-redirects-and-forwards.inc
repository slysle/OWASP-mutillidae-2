<table class="hint-table">
	<tr class="hint-header" 
		id="idURFHintHeader"
		title="Click to open this section"
		onclick="toggleBody(this, window.document.getElementById('idURFHintBody'), window.document.getElementById('idURFHintHeaderImage'));"
		onmouseover="this.style.backgroundColor='#cccccc';this.style.color='#ffffff';"
		onmouseout="this.style.backgroundColor='#FFFFFF';this.style.color='#000000';"
	>
		<td><img id="idURFHintHeaderImage" align="left" style="padding-right: 5px;" alt="Expand Unvalidated Redirects and Forwards Hints" src="./images/down_arrow_16_16.png" />
			Unvalidated Redirects and Forwards Hints
		</td>
	</tr>
	<tr id="idURFHintBody" style="display: none;">
		<td class="hint-body">
			<br/><br/>
			<span class="report-header">Overview</span>
			<br/><br/>
		  	Sites which redirect users to a URL which is passed as a parameter
		  	are vulnerable to arbitrary redirection. An attacker can create
		  	a URL then embed the URL as a parameter which when passed to the 
		  	vulnerable page will cause the user to be redirected to the URL
		  	Unvalidated redirects can make the job of Phishers easier 
		  	since the URL can be made to look like part of a trusted site. 
			<br/><br/>
			<span class="report-header">Discovery Methodology</span>
			<br/><br/>
			Spider the site and note any status codes of 3xx and/or "Location"
			HTTP headers. For each found, inject all parameters on the page
			leading up to the redirection including cookies. Check if any of
			the injected values makes up any part of value of the "Location"
			header (from Location header redirection)
			or if the URL on which the browser lands contains any
			of the injected values (from page rewriting).
			<br/><br/>
			<span class="report-header">Exploitation</span>
			<br/><br/>
			<span class="label">Note: The "Credits" page in this site is vulnerable.</span>
			<br/><br/>
			Once an injectable location is found, inject a URL and observe if the injection
			results in being redirected to the URL. If the injection does not result
			in redirection, check the resulting syntax of the URL. It may be possible 
			to correct some syntax errors.
			<br/><br/>
			<span class="report-header">Example</span>
			<br/><br/>
			On the "credits" page in this site, one of the links is
			<br/>
<code>
	http://localhost/mutillidae/index.php?page=redirectandlog.php&amp;forwardurl=http://www.owasp.org.
</code>
			<br/>
			If an internet connection is available, try using
			<br/>
<code>
	http://www.google.com
</code>
			<br/>
			as the URL passed to the "forwardurl" parameter. The following URL can be entered:
			<br/>
<code>
	http://localhost/mutillidae/index.php?page=redirectandlog.php&amp;forwardurl=http://www.google.com.
</code>			
			<br/>
			If no Internet connection is available, try using
			<br/>
<code>
	http://localhost/mutillidae/capture-data.php
</code>
			<br/>
			as the URL passed to the value to the "forwardurl" parameter.
			<br/>
<code>
	http://localhost/mutillidae/index.php?page=redirectandlog.php&amp;forwardurl=http://localhost/mutillidae/capture-data.php
</code>
			<br/>
		</td>
	</tr>
</table>