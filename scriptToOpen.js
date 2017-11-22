//USED ON ALREADY GRADED ANSWERS
function getAnswer(){
	$(".display_question:not(.incorrect)").each(function(index){
	    var title = $(this).find(".question_text").text();
	    console.log(title);
	    title = title.replace(/\s+/g, '');
	    var correctAnswer = $(this).find(".selected_answer .answer_text").text();
	    console.log(correctAnswer);
	    correctAnswer = correctAnswer.replace(/\s+/g, '');
	    //Set cookie to the title of answer
	    $.cookie(title,correctAnswer);
	});
}
//USED ON QUIZ..
function selectAnswer(){
	$("input").each(function(input){
		$(this).click();
	});
	var rightAnswer = false;
	//Check if we have cookie named title with data in it.
	
	var id;
	$(".display_question").each(function(input){
		answer = $.cookie($(this).find(".question_text").text().replace(/\s+/g, ''));
		$("label").each(function(input){
			//Check for right answer...
			if($(this).text().replace(/\s+/g, '') == answer){
				id = $(this).attr('for');
				rightAnswer = true;
				$("#" + id).click();	
			}
		});
	
	});
}
//STUFF 2.0 TESTING
//
//SHORTENED COOKIES.
//


//USED ON ALREADY GRADED ANSWERS
function getAnswer(){
	var i = 0
	var answers = [];
	while(i<1000){
		if($.cookie(i.toString()) != null){
			answers[i] = $.cookie(i.toString());			
			i++;
			console.log($.cookie(i));
			
		}else{
			break;
		}
	}

	$(".display_question:not(.incorrect)").each(function(index){
	    var title = $(this).find(".question_text").text();
	    console.log(title);
	    title = title.replace(/\s+/g, '');
	    var correctAnswer = $(this).find(".selected_answer .answer_text").text();
	    console.log(correctAnswer);
	    correctAnswer = correctAnswer.replace(/\s+/g, '');
	    //Set cookie to the title of answer

	    $.cookie(i,correctAnswer);
	    i+=1;
	});
}
//USED ON QUIZ..
function selectAnswer(){
	var rightAnswer = false;
	//Check if we have cookie named title with data in it.
	var answers = [];
	var i = 0;
	//Check for right answer...
	while(i < 180){
		if($.cookie(i.toString()) == null) break;
		answers[i] = $.cookie(i.toString());	
		i++;
	}
	var id;
	$(".display_question").each(function(input){
		$("label").each(function(input){			
			i = 0;
			while(i < 180){
				if(answers[i] == null) break;
				if($(this).text().replace(/\s+/g, '') == answers[i]){
					id = $(this).attr('for');
					rightAnswer = true;
					$("#" + id).click();
					break;
				}
				i++;
			}
		});
	
	});
}




//VERSION 3.0
//USED ON ALREADY GRADED ANSWERS
function getAnswer(){
	var i = 0
	var answers = [];
	while(i<1000){
		if($.cookie(i.toString()) != null){
			answers[i] = $.cookie(i.toString());			
			i++;
			console.log($.cookie(i));
			
		}else{
			break;
		}
	}
	
	$(".display_question:not(.incorrect)").each(function(index){
	    var i2 = 0;
	    var setCookie = true;
	    var title = $(this).find(".question_text").text();
	    console.log(title);
	    title = title.replace(/\s+/g, '');
	    var correctAnswer = $(this).find(".selected_answer .answer_text").text();
	    console.log(correctAnswer);
	    correctAnswer = correctAnswer.replace(/\s+/g, '');
	    while(i2<1000){
		if(answers[i2] == null) break;
	 	if(correctAnswer == answers[i2]){ setCookie = false };
		i2++;
	    }
		if(setCookie == true) $.cookie(i,correctAnswer);
	    

	    
	    i+=1;
	});
}
//USED ON QUIZ..
function selectAnswer(){
	var rightAnswer = false;
	//Check if we have cookie named title with data in it.
	var answers = [];
	var i = 0;
	//Check for right answer...
	while(i < 180){
		if($.cookie(i.toString()) == null) break;
		answers[i] = $.cookie(i.toString());	
		i++;
	}
	var id;
	$(".display_question").each(function(input){
		$("label").each(function(input){			
			i = 0;
			while(i < 180){
				if(answers[i] == null) break;
				if($(this).text().replace(/\s+/g, '') == answers[i]){
					id = $(this).attr('for');
					rightAnswer = true;
					$("#" + id).click();
					break;
				}
				i++;
			}
		});
	
	});
}
