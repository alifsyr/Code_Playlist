import psycopg2
ip_address = "52.187.108.147"  # ganti dengan address masing-masing
matkul = "mbd"


def get_db(name):
    db = psycopg2.connect(dbname=matkul, host=ip_address,
                          user=name, password=matkul)
    return db


def test0():
    cursor = get_db("mahasiswa").cursor()
    try:
        cursor.execute('SELECT * FROM penilaian')
        cursor.execute("commit")
    except:
        cursor.execute("rollback")
    cursor.execute('SELECT nim, nama FROM penilaian WHERE nim<18219990')
    [(nim, nama)] = cursor.fetchall()
    print(nim, nama)
    return nim, nama


def test1():
    dsn = get_db("dosen").cursor()
    try:
        dsn.execute("INSERT INTO penilaian (nim) VALUES (13517109)")
        dsn.commit()
        return 0
    except:
        return 1


def test2():
    db = get_db("asisten3")
    ast = db.cursor()
    try:
        ast.execute("UPDATE penilaian SET nilai=5 WHERE nim = 18219993")
        ast.commit()
        return 0
    except:
        return 1


def test3():
    try:
        db = get_db("asisten3")
        ast = db.cursor()
        ast.execute("UPDATE penilaian SET nilai=3 WHERE nim = 18219993")
        db.commit()
        mhs = get_db("mahasiswa").cursor()
        mhs.execute("SELECT indeks FROM penilaian WHERE nim = 18219993")
        data = mhs.fetchone()
        return 1 if data[0] == 'B' else 0
    except:
        return 0


def test4():
    cursor = get_db("dosen").cursor()
    cursor.execute("SELECT r.rolsuper, r.rolcreaterole, r.rolcanlogin FROM pg_catalog.pg_roles r \
    WHERE r.rolname LIKE 'dosen'")
    data = cursor.fetchone()
    return 1 if not(data[0]) and data[1] and data[2] else 0


def test5():
    cursor = get_db("dosen").cursor()
    cursor.execute("SELECT r.rolcanlogin FROM pg_catalog.pg_roles r \
    WHERE r.rolname LIKE 'asisten'")
    return 1 if not cursor.fetchone()[0] else 0


def test6():
    cursor = get_db("dosen").cursor()
    cursor.execute("SELECT \
      COUNT (DISTINCT ARRAY(SELECT b.rolname \
        FROM pg_catalog.pg_auth_members m \
        JOIN pg_catalog.pg_roles b ON (m.roleid = b.oid) \
        WHERE m.member = r.oid)) \
    FROM pg_catalog.pg_roles r \
    WHERE r.rolname LIKE 'asisten_'")
    return 1 if cursor.fetchone()[0] == 2 else 0


def test7():
    cursor = get_db("dosen").cursor()
    cursor.execute("SELECT c.relname, \
  pg_catalog.array_to_string(c.relacl, E'\n'), \
  pg_catalog.array_to_string(ARRAY( \
    SELECT attname || E':\n  ' || pg_catalog.array_to_string(attacl, E'\n  ') \
    FROM pg_catalog.pg_attribute a \
    WHERE attrelid = c.oid AND NOT attisdropped AND attacl IS NOT NULL \
  ), E'\n')\
FROM pg_catalog.pg_class c \
     LEFT JOIN pg_catalog.pg_namespace n ON n.oid = c.relnamespace \
WHERE c.relkind IN ('r','v','m','S','f','p') \
    AND c.relname LIKE 'penilaian' \
  AND n.nspname !~ '^pg_' AND pg_catalog.pg_table_is_visible(c.oid)")
    data = cursor.fetchone()
    return 1 if data[1].split('\n')[1].split('=')[1].split("/")[0] == "a*r*w*" else 0


def test8():
    cursor = get_db("dosen").cursor()
    cursor.execute("SELECT c.relname, \
  pg_catalog.array_to_string(c.relacl, E'\n'), \
  pg_catalog.array_to_string(ARRAY( \
    SELECT attname || E':\n  ' || pg_catalog.array_to_string(attacl, E'\n  ') \
    FROM pg_catalog.pg_attribute a \
    WHERE attrelid = c.oid AND NOT attisdropped AND attacl IS NOT NULL \
  ), E'\n')\
FROM pg_catalog.pg_class c \
     LEFT JOIN pg_catalog.pg_namespace n ON n.oid = c.relnamespace \
WHERE c.relkind IN ('r','v','m','S','f','p') \
    AND c.relname LIKE 'penilaian' \
  AND n.nspname !~ '^pg_' AND pg_catalog.pg_table_is_visible(c.oid)")
    data = cursor.fetchone()
    return 1 if len(set([(x.split("=")[0], x.split("=")[1].split('/')[0]) for x in [x.strip()
                                                                                    for x in data[2].split('\n')] if "=" in x])) == 3 else 0


def main():
    score = 0
    nim, nama = test0()
    score += test1()
    score += test2()
    score += test3()
    score += test4()
    score += test5()
    score += test6()
    score += test7()
    score += test8()
    print("test 1",test1())
    print("test 2",test2())
    print("test 3",test3())
    print("test 4",test4())
    print("test 5",test5())
    print("test 6",test6())
    print("test 7",test7())
    print("test 8",test8())
    print("Score: " + str(score) + "/8")
    db = get_db("dosen")
    dsn = db.cursor()
    dsn.execute(
        "UPDATE penilaian SET nilai = %s WHERE nim = %s AND nama = %s", (score//2, nim, nama))
    db.commit()
    mhs = get_db("mahasiswa").cursor()
    mhs.execute(
        "SELECT nim, nama, indeks FROM penilaian WHERE nim = %s", [nim])
    print("Indeks: " + str(mhs.fetchone()[2]))


main()