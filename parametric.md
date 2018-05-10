---
layout: default
title: Parametric benchmark functions
---
{% include sidebar.html %}
<div class="home">

<h2>Parametric Functions</h2>
Parameteric functions are functions their behaviour can be modified with parameters that are used in their definition. 
A list of functions that have parameters in their definition is presented below. <br /> <br />

<ol >
{% for post in site.pages %}
	{% if post.resource == true %}
		{% if post.tags contains 'parameteric' %}
			 <li>
			<h3>
			  <a href="{{ post.url | prepend: site.baseurl }}">{{ post.title }}</a>
			  <br />
			{% assign tags = post.tags | split:' ' %}
			<ul>
				{% for tag in tags %}
				<code><a class="fcntag" href="{{ tag | prepend:'/' | prepend: site.baseurl }}">{{ tag}}</a></code>
				{% endfor %}
			</ul>
			</h3>
		  </li>
		{% endif %}
	{% endif %}
{% endfor %}
</ol>

</div>