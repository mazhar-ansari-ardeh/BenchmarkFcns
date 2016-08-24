---
layout: default
title: Benchmark functions
---
<div class="home">

  <h1 class="page-heading">Implemented Functions</h1>

  <ol >
    {% for post in site.pages %}
	{% if post.resource == true %}
      <li>
        <h3>
          <a href="{{ post.url | prepend: site.baseurl }}">{{ post.title }}</a>
        </h3>
      </li>
    {% endif %}
	{% endfor %}
  </ol>

</div>