/*console.log("cest carrés");*/

const contenu = document.getElementById("listeProjets");

let c=0;
for(let j=0;j<4; j++)
{
const element = document.createElement("div");
element.className = "projet" ;
element.textContent = `Projet ${j+1}`;
contenu.appendChild(element);
c++;

}

const flècheDroit = document.querySelector('.flèche.droit');
const flècheGauche = document.querySelector(".flèche.gauche");
const defilement = 330; //largeur p et gap


flècheDroit.addEventListener("click", function()
    { contenu.scrollBy( { left: defilement, behavior : "smooth"} );}
    );
flècheGauche.addEventListener("click", function()
    { contenu.scrollBy( { left: -defilement, behavior : "smooth" } );}
    );





 const projets = document.querySelectorAll('.projet');


 if (projets.length<=4)
 {
    contenu.style.justifyContent="center";

 }
projets[0].innerHTML = 
` <div class = "presentationProjet">
<h2>Flood-it</h2>
<p>Language: C++</p>
<p>Solveur du jeu optimisé, 2025</p>  
<img class="photo_jeux" src="Projet_floodit/Img.png" />
<a class="bouton_bas" href="Projet_Floodit.zip" download="Flood-It">Télécharger (zip)</a>
</div>
  
`;

projets[1].innerHTML = 
` <div class = "presentationProjet">
<h2>Jeu R-Type</h2>
<p>Language: C++</p>
<p>Bibiliothèque graphique LibTableauNoir</p>  
<img class="photo_jeux" src="R-type.png" />
<a class="bouton_bas" href="Satkunarajah_Sasmithan.zip" download="R-Type">Télécharger (zip)</a>
</div>
  
`;

projets[2].innerHTML = 
` <div class = "presentationProjet">
<h2>Jeu shadow fight</h2>
<p>Language: python</p>
<p>Bibiliothèque pygame, 2O23</p>  
<img class="photo_jeux" src="screen-shadow.png" />
<a class="bouton_bas" href="shadow.zip" download="shadow-fight">Télécharger (zip)</a>
</div>
  
`;
projets[3].innerHTML = 
` <div class = "presentationProjet">
<h2>site avec chatbot</h2>
<p>Language: html,css,js</p>
<p> réalisé en 2022</p>  
<img class="photo_jeux" src="screen-nsi.png" />
<a class="bouton_bas" href="nsi.zip" download="nsi">Télécharger (zip)</a>
</div>
  
`;

    