inherit BULLETIN_BOARD;

void create()
{
        set_name("�̼ұ��������԰�", ({ "board" }));
        set("location", "/d/shaolin/shang_dating");
        set("board_id", "shang_b");
        set("long", "����һ��ר���̼ұ�����ʹ�õ����԰塣\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

