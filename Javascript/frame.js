jQuery(document).ready(function($) {
  $('.nav-tabs > li > a').on('click', function(event) {
    //avoid <a> tag to load his href
    event.preventDefault();
    //getting the main subjects
    var id_of_selected = $(this).attr('load-in');
    var link_to_load = $(this).attr('href');
    var iframe_to_load = $(document).find('#' + id_of_selected);
    console.log(iframe_to_load);
    //make the magic
    if (iframe_to_load.length) {
      iframe_to_load.attr('src', link_to_load); //this fires the link to destinated iframe
      iframe_to_load.parent().addClass('active'); //this make the parent div container of iframe visible
    }

  });
});