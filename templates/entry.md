Title: {{view.fun.name}}
Status: hidden

## References

* [Official documentation]({{ BOOST_DOC_URL + view.fun.doclink }})
* [Source code]({{ BOOST_HEADER_URL + view.fun.main_header }})

## Headers
`{{view.fun.name}}` is available by including
{% if len(view.fun.headers) > 1 %} any of the following headers:{% else %} the following header:{% endif %}

{% for header in view.fun.headers %}
  * `{{header}}`{% if not loop.last %} or{% endif %}
{%- endfor %}

## Examples
{% for example in view.fun.examples %}
### {{example.name.replace('_', '\\_')}}

<span class="add-cppsh-link" style='display:none'></span>

    :::cpp
{{indent(example.code, '    ')}}

Output:

{{indent(example.output or '\u200b', '    ')}}

&nbsp;

{% endfor %}
