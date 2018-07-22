---
layout: default
title: plotting functions for benchmark functions
---
{% include sidebar.html %}
{% include adsense.md %}
<div class="home">

  <h2>Helper Plotting Functions</h2>
Because of the way that functions in this library receive their input, it is not very straightforward to plot them. Consequently, 
these helper functions are added to ease generating various plots for the functions. 

  <ol >
    {% for post in site.pages %}
	  {% if post.plotting == true %}
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

