---
layout: default
title: 1-dimensional benchmark functions
---
<div class="home">

  <h2>1-dimensional Functions</h2>

  <ol >
    {% for post in site.pages %}
	{% if post.resource == true %}
	{% if post.tags contains '1-dimensional' %}
		 <li>
        <h3>
          <a href="{{ post.url | prepend: site.baseurl }}">{{ post.title }}</a>
		  <br />
		{% assign tags = post.tags | split:&nbsp; %}
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