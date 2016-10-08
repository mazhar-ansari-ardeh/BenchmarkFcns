---
layout: default
title: Non-Separable benchmark functions
---
{% include sidebar.html %}
<div class="home">

  <h2>Non-separable Functions</h2>

  <ol >
    {% for post in site.pages %}
	{% if post.resource == true %}
	{% if post.tags contains 'non-separable' %}
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