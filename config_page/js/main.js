var hardware;
var features = {
	bw: false,
	color: false,
	rect: false,
	round: false,
	health: false,
	hr: false,
	bigrect: false
};

var hardware = parse('hardware');

fillFeatures(hardware, features);

console.log(hardware);
console.log(features);

function fillFeatures(hardware, features) {
	switch(hardware) {
		case 'aplite':
			features.bw = true;
			features.rect = true;
			break;
		case 'basalt':
			features.color = true;
			features.rect = true;
			features.health = true;
			break;
		case 'chalk':
			features.color = true;
			features.round = true;
			features.health = true;
			break;
		case 'diorite':
			features.bw = true;
			features.rect = true;
			features.health = true;
			features.hr = true;
			break;
		case 'emery':
			features.color = true;
			features.rect = true;
			features.health = true;
			features.hr = true;
			break;
		default:
			features.color = true;
			features.rect = true;
			features.health = true;
			features.hr = true;
			break;
	}
}

function parse(val) {
    var result = "Not found",
        tmp = [];
    location.search
    //.replace ( "?", "" ) 
    // this is better, there might be a question mark inside
    .substr(1)
        .split("&")
        .forEach(function (item) {
        tmp = item.split("=");
        if (tmp[0] === val) result = decodeURIComponent(tmp[1]);
    });
    return result;
}

function getColorByName(name) {
	return {
		"Diamond":		   202,
		"Ruby": 		   226,
		"Fire":			   224,
		"Forest":		   200,
		"Quartz": 		   255,
		"Red":			   240,
		"Green":		   204,
		"Blue":			   195,
		"Yellow":		   252,
		"Cyan":			   207,
		"Magenta":		   243,
		"Violet":		   227,
		"Orange":		   244,
		"Vivid Cerulean":  203,
		"Chrome Yellow":   248,
		"Spring Green":	   206,
		"Black":		   192,
		"Dark Gray":	   213,
		"Light Gray":	   234,
		"White":		   255
	}[name];
}

function getVariationByName(name) {
	return ["Diamond", "Ruby", "Fire", "Forest", "Quartz"].indexOf(name) != -1;
}


function getBezelByModelName(model) {
	return {
		"pebble_time_round_silver_14":		       "pebble-time-round-14mm-silver",
		"pebble_time_round_black_14":		       "pebble-time-round-14mm-black",
		"pebble_time_round_rose_gold_14":		   "pebble-time-round-14mm-rose-gold",
		"pebble_time_round_silver_20":		       "pebble-time-round-20mm-silver",
		"pebble_time_round_black_20":		       "pebble-time-round-20mm-black",
		
		"pebble_time_steel_black":		           "pebble-time-steel-black",
		"pebble_time_steel_silver":		           "pebble-time-steel-silver",
		"pebble_time_steel_gold":		           "pebble-time-steel-gold",
		
		"pebble_time_red":		                   "pebble-time-red",
		"pebble_time_white":		               "pebble-time-white",
		"pebble_time_black":		               "pebble-time-black",
		
		"pebble_steel_silver":		               "pebble-steel-silver",
		"pebble_steel_black":		               "pebble-steel-black",
		
		"pebble_black":		                       "pebble-black",
		"pebble_grey":		                       "pebble-grey",
		"pebble_white":		                       "pebble-white",
		"pebble_red":		                       "pebble-red",
		"pebble_orange":		                   "pebble-orange",
		"pebble_blue":		                       "pebble-blue",
		"pebble_green":		                       "pebble-green",
		"pebble_pink":		                       "pebble-pink"

	}[model.replace(/mm$/, '')];
}

function updatePreview() {
    var n = '';
    var o2 = '';
    var o = '';
    var b = '';
    var r = '';
    if (features.color) {
        n = 'img/n-'+$('#num_color').val().replace(' ', '-')+'.png';
        o2 = 'img/0-'+$('#num_color').val().replace(' ', '-')+'.png';
        o = 'img/o-'+$('#orn_color').val().replace(' ', '-')+'.png';
        b = 'img/b-'+$('#bg_color').val().replace(' ', '-')+'.png';
        r = 'img/r-'+$('#orn_color').val().replace(' ', '-')+'.png';
    } else {
        if ($('#invert').prop("checked")) {
            n = 'img/n-Black.png';
            o2 = 'img/0-Black.png';
            o = 'img/o-Black.png';
            b = 'img/b-White.png';
        } else {
            n = 'img/n-White.png';
            o2 = 'img/0-White.png';
            o = 'img/o-White.png';
            b = 'img/b-Black.png';
        }
        if($('#monochrome').prop("checked")) {
            o = 'img/o-Aplite-Gray.png';
        }
    }

    $('.preview-n').attr('src', n);
    $('.preview-o').attr('src', o);
    $('.preview-b').attr('src', b);
    $('.preview-o2').attr('src', o2);
    if (features.color) {
        $('.preview-r').attr('src', r);
    }
    
    if ($('#zero').prop("checked")) {
        $('.showzero').addClass('activeshowzero');
    } else {
        $('.showzero').removeClass('activeshowzero');
    }
    
    if ($('#date').prop("checked")) {
        $('.eurodate').addClass('activeeurodate');
    } else {
        $('.eurodate').removeClass('activeeurodate');
    }
    
    if ($('#center').prop("checked") && $('#date').prop("checked")) {
        $('.preview-centeralign').addClass('activecenteralign');
    } else {
        $('.preview-centeralign').removeClass('activecenteralign');
    }
    if ($('#size').prop("checked") && features.rect) {
        $('.preview-scaler').addClass('scaled');
    } else {
        $('.preview-scaler').removeClass('scaled');
    }
}
function updateBottomRow() {
    if (parseInt($('#bottomrow').val(), 10) > 0) {
        $('.date-settings-hide').hide();
    } else {
        $('.date-settings-hide').show();
    }
}

function updateStepDisplay() {
    if (parseInt($('#bottomrow').val(), 10) == 2 || parseInt($('#wristflick').val(), 10) == 2) {
        $('#step-settings').show();
    } else {
        $('#step-settings').hide();
    }
    if (parseInt($('#wristflick').val(), 10) == 2) {
        $('#quips').show();
    } else {
        $('#quips').hide();
    }
}

function updateStepgoalVisibility() {
	if ($("#dynamicstepgoal").prop("checked")) {
		$('.dynamicstepgoalhide').hide();
	} else {
		$('.dynamicstepgoalhide').show();
	}
}

function updateStepGoalText() {
    var stepgoal = $('#stepgoal').val();
    if (stepgoal < 4000) {
        $('#stepgoaltext').html('Are you sure that\'s all you can do?');
    } else if (stepgoal < 8000) {
        $('#stepgoaltext').html('Not the worst step goal.');
    } else if (stepgoal < 12000) {
        $('#stepgoaltext').html('Good, 10,000 steps are rumored to be recommended by the WHO.');
    } else if (stepgoal < 16000) {
        $('#stepgoaltext').html('Really good, keep pushing yourself!');
    } else if (stepgoal < 20000) {
        $('#stepgoaltext').html('That\'s a mighty step goal. I\'m impressed.');
    } else {
        $('#stepgoaltext').html('Whoa, are you training for a marathon or something?');
    }
}

$('#num_color, #orn_color, #bg_color, #date, #zero, #center, #invert, #monochrome, #size').on('change', function() {
    updatePreview();
});

$('#bottomrow').change(function() {
    updateBottomRow();
});

$('#bottomrow, #wristflick').change(function() {
    updateStepDisplay();
});

$('#stepgoal').change(function() {
    updateStepGoalText();
});

$('#dynamicstepgoal').change(function() {
    updateStepgoalVisibility();
});

function updateNightsaver() {
    if ($('#nightsaver').prop("checked")) {
        $('.show-on-nightsaver').show();
    } else {
        $('.show-on-nightsaver').hide();
    }
}

$('#nightsaver').on('change', function() {
    updateNightsaver();
});

function updateRound() {
    if (features.round) {
        $('.preview').addClass('round-preview');
    }
}

(function() {
  loadOptions();
  submitHandler();
})();

function getDataToSend() {
	bg_color = $("#bg_color").val();
	num_color = $("#num_color").val();
	orn_color = $("#orn_color").val();
	data = {
	    large_mode: ''+$("#size").prop("checked"),
	    eu_date: ''+$("#date").prop("checked"),
	    quick_start: ''+$("#delay").prop("checked"),
	    leading_zero: ''+$("#zero").prop("checked"),
	    background_color: getColorByName(bg_color),
	    number_base_color: getColorByName(num_color),
	    number_variation: 0+getVariationByName(num_color),
	    ornament_base_color: getColorByName(orn_color),
	    ornament_variation: 0+getVariationByName(orn_color),
	    invert: ''+$("#invert").prop("checked"),
	    monochrome: ''+$("#monochrome").prop("checked"),
	    center: ''+$("#center").prop("checked"),
	    btvibe: ''+$("#btvibe").prop("checked"),
	    contrast: ''+$("#contrast").prop("checked"),
	    nightsaver: ''+$("#nightsaver").prop("checked"),
	    ns_start: $("#ns_start").val(),
	    ns_stop: $("#ns_stop").val(),
	    backlight: ''+$("#backlight").prop("checked"),
	    weekday: ''+$("#weekday").prop("checked"),
	    bottomrow: $('#bottomrow').val(),
	    wristflick: $('#wristflick').val(),
	    stepgoal: $('#stepgoal').val(),
	    dynamicstepgoal: ''+$("#dynamicstepgoal").prop("checked"),
	    cheeky: ''+$("#cheeky").prop("checked")
	};
	return data;
}

function saveData(){
	if(localStorage) {
		toStore = {
			size: ''+$("#size").prop("checked"),
			date: ''+$("#date").prop("checked"),
			delay: ''+$("#delay").prop("checked"),
			zero: ''+$("#zero").prop("checked"),
			bg_color: $("#bg_color").val(),
			num_color: $("#num_color").val(),
			orn_color: $("#orn_color").val(),
			invert: ''+$("#invert").prop("checked"),
			monochrome: ''+$("#monochrome").prop("checked"),
			center: ''+$("#center").prop("checked"),
			btvibe: ''+$("#btvibe").prop("checked"),
			contrast: ''+$("#contrast").prop("checked"),
			nightsaver: ''+$("#nightsaver").prop("checked"),
			ns_start: $("#ns_start").val(),
			ns_stop: $("#ns_stop").val(),
			backlight: ''+$("#backlight").prop("checked"),
			weekday: ''+$("#weekday").prop("checked"),
    	    bottomrow: $('#bottomrow').val(),
    	    wristflick: $('#wristflick').val(),
    	    stepgoal: $('#stepgoal').val(),
			dynamicstepgoal: ''+$("#dynamicstepgoal").prop("checked"),
    	    cheeky: ''+$("#cheeky").prop("checked")
		};
		localStorage.setItem("lastconfig", JSON.stringify(toStore));
	}
}

function restoreData(){
	if(localStorage) {
		stored = JSON.parse(localStorage.getItem("lastconfig"));
		if(stored){
			$("#size").prop("checked", (stored.size === 'true'));
			$("#date").prop("checked", (stored.date === 'true'));
			$("#delay").prop("checked", (stored.delay === 'true'));
			$("#zero").prop("checked", (stored.zero === 'true'));
			$("#bg_color").val(stored.bg_color);
			$("#num_color").val(stored.num_color);
			$("#orn_color").val(stored.orn_color);
			$("#invert").prop("checked", (stored.invert === 'true'));
			$("#monochrome").prop("checked", (stored.monochrome === 'true'));
			$("#center").prop("checked", (stored.center === 'true'));
			$("#btvibe").prop("checked", (stored.btvibe === 'true'));
			$("#contrast").prop("checked", (stored.contrast === 'true'));
			$("#nightsaver").prop("checked", (stored.nightsaver === 'true'));
			if (stored.ns_start) { $("#ns_start").val(stored.ns_start); }
			if (stored.ns_start) { $("#ns_stop").val(stored.ns_stop); }
			$("#backlight").prop("checked", (stored.backlight === 'true'));
			$("#weekday").prop("checked", (stored.weekday === 'true'));
			if (stored.bottomrow) { $("#bottomrow").val(stored.bottomrow); }
			if (stored.wristflick) { $("#wristflick").val(stored.wristflick); }
			if (stored.stepgoal) { $("#stepgoal").val(stored.stepgoal); }
			$("#dynamicstepgoal").prop("checked", (stored.dynamicstepgoal === 'true'));
			$("#cheeky").prop("checked", (stored.cheeky === 'true'));
		}
		updatePreview();
		updateBottomRow();
		updateStepDisplay();
		updateNightsaver();
        updateRound();
        $('#stepgoal').change();
        $('#stepgoallabel').val($('#stepgoal').val());
	}
	
	if(features.bw) {
      $('option.bwhide').remove();
    }
    if(!features.health) {
	  console.log('health not supported');
	  console.log('bottomrow is "'+$('#bottomrow').val()+'"');
	  console.log('wristflick is "'+$('#wristflick').val()+'"');
      if($('#bottomrow').val() == "" || $('#bottomrow').val() == "2" || $('#bottomrow').val() == "3") {
          $('#bottomrow').val("0");
      }
      if($('#wristflick').val() == "" || $('#wristflick').val() == "2") {
          $('#wristflick').val("0");
      }
	  $('option.nohealthhide').remove();
    }
    if(!features.hr) {
	  console.log('hr not supported');
	  console.log('bottomrow is "'+$('#bottomrow').val()+'"');
      if($('#bottomrow').val() == "" || $('#bottomrow').val() == "3") {
          $('#bottomrow').val("0");
      }
      $('option.nohrhide').remove();
    }
}



function submitHandler() {
  var $submitButton = $('#send');

  $submitButton.on('click', function() {
    console.log('Submit');

    var return_to = getQueryParam('return_to', 'pebblejs://close#');
    document.location = return_to + encodeURIComponent(JSON.stringify(getAndStoreConfigData()));
  });
}

function loadOptions() {
  $('.'+hardware+'hide').hide();
  $('.'+hardware+'show').show();
  if(features.rect) {
      $('.recthide').hide();
  } else {
      $('.roundhide').hide();
  }
  if(features.bw) {
      $('.bwhide').hide();
  } else {
      $('.colorhide').hide();
  }
  if(!features.health) {
      $('.nohealthhide').remove();
  }
  if(!features.hr) {
      $('.nohrhide').remove();
  }
  
  var bezelimg = 'chalk';
  var previewhardware = 'for-chalk';
  
  if(parse('model') != "Not found" && getBezelByModelName(parse('model')) != undefined) {
      console.log('model string present: '+parse('model'));
      bezelimg = getBezelByModelName(parse('model'));
      console.log('image name: '+bezelimg);
  } else {
      if(features.rect) {
          bezelimg = 'basalt';
          if(features.bw) {
              bezelimg = 'aplite';
          }
      }
  }
  if(features.rect) {
      previewhardware = 'for-basalt';
      if(features.bw) {
          previewhardware = 'for-aplite';
      }
  }
  $('.previewbezel').css('background-image', 'url(frames/'+bezelimg+'.png)');
  $('.previewbezel, .preview').addClass(previewhardware);
  
  restoreData();
}

function getAndStoreConfigData() {
  saveData();
  return getDataToSend();
}

function getQueryParam(variable, defaultValue) {
  var query = location.search.substring(1);
  var vars = query.split('&');
  for (var i = 0; i < vars.length; i++) {
    var pair = vars[i].split('=');
    if (pair[0] === variable) {
      return decodeURIComponent(pair[1]);
    }
  }
  return defaultValue || false;
}