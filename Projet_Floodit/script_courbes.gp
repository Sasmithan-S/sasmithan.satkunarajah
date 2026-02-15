set terminal png size 1200,800 enhanced font "Arial,12"
set output "Courbes/nbcl/exo1_nbcl.png"

set title "Evolution du temps de sequence aleaoire rec en fonction du nombre de couleurs"
set xlabel "nbcl"
set ylabel "Temps (s)"
plot "Courbes/donnees/temps/donnees_exo1_nbcl.txt" with linespoints title "sequence aleaoire rec"


set terminal png size 1200,800 enhanced font "Arial,12"
set output "Courbes/dim/exo1_dim.png"

set title "Evolution du temps de sequence aleaoire rec en fonction de dim"
set xlabel "dim"
set ylabel "Temps (s)"
plot "Courbes/donnees/temps/donnees_exo1_dim.txt" with linespoints title "sequence aleaoire rec"






set terminal png size 1200,800 enhanced font "Arial,12"
set output "Courbes/nbcl/exo2_nbcl.png"

set title "Evolution du temps de sequence aleaoire rapide en fonction du nombre de couleurs"
set xlabel "nbcl"
set ylabel "Temps (s)"
plot "Courbes/donnees/temps/donnees_exo2_nbcl.txt" with linespoints title "sequence aleaoire rapide"



set terminal png size 1200,800 enhanced font "Arial,12"
set output "Courbes/dim/exo2_dim.png"

set title "Evolution du temps de sequence aleaoire rapide en fonction de dim"
set xlabel "dim"
set ylabel "Temps (s)"
plot "Courbes/donnees/temps/donnees_exo2_dim.txt" with linespoints title "sequence aleaoire rapide"







set terminal png size 1200,800 enhanced font "Arial,12"
set output "Courbes/nbcl/exo3_nbcl.png"

set title "Evolution du temps de max bordure en fonction du nombre de couleurs"
set xlabel "nbcl"
set ylabel "Temps (s)"
plot "Courbes/donnees/temps/donnees_exo3_nbcl.txt" with linespoints title "max bordure"



set terminal png size 1200,800 enhanced font "Arial,12"
set output "Courbes/dim/exo3_dim.png"

set title "Evolution du temps de max bordure en fonction de dim"
set xlabel "dim"
set ylabel "Temps (s)"
plot "Courbes/donnees/temps/donnees_exo3_dim.txt" with linespoints title "max bordure"





set terminal png size 1200,800 enhanced font "Arial,12"
set output "Courbes/nbcl/exo4_nbcl.png"

set title "Evolution du temps de max bordure zone en fonction du nombre de couleurs"
set xlabel "nbcl"
set ylabel "Temps (s)"
plot "Courbes/donnees/temps/donnees_exo4_nbcl.txt" with linespoints title "max bordure zone"



set terminal png size 1200,800 enhanced font "Arial,12"
set output "Courbes/dim/exo4_dim.png"

set title "Evolution du temps de max bordure zone en fonction de dim"
set xlabel "dim"
set ylabel "Temps (s)"
plot "Courbes/donnees/temps/donnees_exo4_dim.txt" with linespoints title "max bordure zone"





set terminal png size 1200,800 enhanced font "Arial,12"
set output "Courbes/nbcl/courbes_nbcl.png"

set title "Comparaison du temps d'executions (Echelle log) du temps des differentes fonctions du nombre de couleurs"
set xlabel "nbcl"
set ylabel "Temps (s)"
set logscale y
plot 'Courbes/donnees/temps/donnees_exo1_nbcl.txt' with linespoints title 'sequence aleaoire rec', 'Courbes/donnees/temps/donnees_exo2_nbcl.txt' with linespoints title 'sequence aleaoire rapide' , 'Courbes/donnees/temps/donnees_exo3_nbcl.txt' with linespoints title 'max bordure' , 'Courbes/donnees/temps/donnees_exo4_nbcl.txt' with linespoints title 'max bordure zone'



set terminal png size 1200,800 enhanced font "Arial,12"
set output "Courbes/dim/courbes_dim.png"

set title "Comparaison du temps d'excutions (Echelle log) des différentes fonctions en fonction de dim "
set xlabel "dim"
set ylabel "Temps (s)"
set logscale y
plot 'Courbes/donnees/temps/donnees_exo1_dim.txt' with linespoints title 'sequence aleaoire rec', 'Courbes/donnees/temps/donnees_exo2_dim.txt' with linespoints title 'sequence aleaoire rapide', 'Courbes/donnees/temps/donnees_exo3_dim.txt' with linespoints title 'max bordure', 'Courbes/donnees/temps/donnees_exo4_dim.txt' with linespoints title 'max bordure zone'



#############################################################################################################

set terminal png size 1200,800 enhanced font "Arial,12"
set output "Courbes/courbes_dim_coups.png"

set title "Comparaison du nombres de coups des  fonctions maxbourdure et maxbourdurezone en fonction de dim"
set xlabel "dim"
set ylabel "Temps (s)"
plot 'Courbes/donnees/coups/donnees_exo3_dim.txt' with linespoints title 'max bordure', 'Courbes/donnees/coups/donnees_exo4_dim.txt' with linespoints title 'max bordure zone'

set terminal png size 1200,800 enhanced font "Arial,12"
set output "Courbes/courbes_nbcm_coups.png"

set title "Comparaison du nombres de coups des  fonctions maxbourdure et maxbourdurezone en fonction du nombre de couleurs"
set xlabel "dim"
set ylabel "Temps (s)"
plot 'Courbes/donnees/coups/donnees_exo3_nbcl.txt' with linespoints title 'max bordure', 'Courbes/donnees/coups/donnees_exo4_nbcl.txt' with linespoints title 'max bordure zone'

