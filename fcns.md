---
layout: default
title: Benchmark functions
---
{% include sidebar.html %}
{% include adsense.md %}
<div class="home">

  <h2>Implemented Functions</h2>

  <ol >
    {% for post in site.pages %}
	{% if post.resource == true %}
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
	{% endfor %}
  </ol>

</div>
