---
layout: default
title: Benchmark functions
---
<div class="home">

  <h2>Implemented Functions</h2>

  <ol >
    {% for post in site.pages %}
	{% if post.resource == true %}
      <li>
        <h3>
          <a href="{{ post.url | prepend: site.baseurl }}">{{ post.title }}</a>
		  <br /><code>{{ post.tags }}</code>
        </h3>
      </li>
    {% endif %}
	{% endfor %}
  </ol>

</div>