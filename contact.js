const formContact = document.getElementById("formContact");

formContact.addEventListener("submit", function (e) {
  e.preventDefault();

  const nom = document.getElementById("nom").value;
  const email = document.getElementById("email").value;
  const message = document.getElementById("message").value;

  const sujet = `Message de ${nom} via le site`;
  const corps = `${message}\n\n---\nDe : ${nom} (${email})`;

  const lien = `mailto:sasmithan.satkunarajah@gmail.com?subject=${encodeURIComponent(sujet)}&body=${encodeURIComponent(corps)}`;

  window.location.href = lien;
});
