Title: Boost Range For Humans

{% for category in view %}
{% if category.level_headers[0] %}##{{category.level_headers[0]}}{% endif %}
{% if category.level_headers[1] %}###{{category.level_headers[1]}}{% endif %}
{% if category.level_headers[2] %}####{{category.level_headers[2]}}{% endif %}

  {% for fun in category.functions %}
  * <a href="{{fun.name.replace('::', '-') + '.html'}}">{{fun.name}}</a>
  {%- endfor %}

{% endfor %}
