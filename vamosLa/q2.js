var arr   = [6, 10, 4, 21, 9, 0, 53],



   iMaior = 0,



   iMenor = 0,



   i =0;







//



// Sua lógica



//



for(i = 0; i < arr.length; i++) {



   if (arr[i] > arr[iMaior]) {



       iMaior = i;



   }







   if (arr[i] < arr[iMenor]) {



      iMenor = i;



   }



}