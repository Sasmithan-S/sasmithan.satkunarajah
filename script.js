/*console.log("cest carrés");*/

const contenu = document.getElementById("listeProjets");

let c=0;
for(let j=0;j<10; j++)
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


 const projet1 = document.querySelector('.projet')
projet1.innerHTML = 
` <div class = "presentationProjet">
<h2>Jeu R-Type</h2>
<p>Language: C++</p>
<p>Bibiliothèque graphique LibTableauNoir</p>  
<img class="photo_1" src="R-type.png" />
<a class="bouton_bas" href="Satkunarajah_Sasmithan.zip" download="CV.pdf">Télécharger (zip)</a>
</div>
  
`;
    