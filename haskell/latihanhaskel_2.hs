-- menghitung jumlah detik - jmlhDetik (j, m, d)
module JmlhDetik where
-- DESKRIPSI DAN SPESIFIKASI
jmlhDetik :: Int -> Int -> Int -> Int
-- jmlhDetik (j,m,d) adalah sebuah fungsi yang 
-- menerima masukan jam (j), menit (m), detik (d)
-- yang ketiganya bertipe integer lalu menghitung jumlah detiknya

-- REALISASI
jmlhDetik j m d =
	if ( j >= 0 && j <= 23) && ( m >= 0 && m <= 59) && ( d >= 0 && d <= 59 ) then (j*3600) + (m*60) +d
	 else 0
