const text1a = document.getElementById("text1a");
const text1b = document.getElementById("text1b");
const text2 = document.getElementById("text2");
const cursor = document.getElementById("cursor");
const textone=["Hello 🖐","I'm  Vineeth K V"];
const texts = ["A web developer.","And IoT enthusiast.","Thanks for visiting!"];
let index = 0;
let charIndex = 0;
let isDeleting = false;

function typetext1()
{ const currentText2 = textone[index];
  if ((charIndex < currentText2.length)&&index==0)
  {
    text1a.textContent += currentText2.charAt(charIndex);
     charIndex++;
     setTimeout(typetext1, 100);
  }
  else if ((charIndex < currentText2.length)&&index==1)
  {
    text1b.textContent += currentText2.charAt(charIndex);
     charIndex++;
     setTimeout(typetext1, 100);
  }
  else if(index<1)
  {
    charIndex=0;
    index++;
    setTimeout(typetext1, 100);
  }
  else
  {
    charIndex=0;
    index=0;
    typeAndDeleteText();
  }
}


function typeAndDeleteText() {
  const currentText = texts[index];

  if (!isDeleting && charIndex < currentText.length)
   { 
     text2.textContent += currentText.charAt(charIndex);
     charIndex++;
     setTimeout(typeAndDeleteText, 20); 
  } 
  else if (isDeleting && charIndex >= 0) 
  { 
    text2.textContent = currentText.slice(0, charIndex);
    charIndex--;
    setTimeout(typeAndDeleteText, 10); 
  } 
  else 
  {
    isDeleting = !isDeleting;

    if (!isDeleting) {
      index = (index + 1) % texts.length;
    }

    setTimeout(typeAndDeleteText, 1000); 
  }
}

typetext1();
