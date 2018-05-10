---
layout: default
title: Continuous benchmark functions
---
{% include sidebar.html %}
<div class="home">

  <h2>Continuous Functions</h2>

  <ol >
    {% for post in site.pages %}
	{% if post.resource == true %}
	{% if post.tags contains 'continuous' %}
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