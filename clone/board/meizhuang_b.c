inherit BULLETIN_BOARD;

void create()
{
        set_name("÷ׯ�������԰�", ({ "board" }) );
        set("location", "/d/meizhuang/houting");
        set("board_id", "meizhuang_b");
        set("long", "����һ��ר��÷ׯ����ʹ�õ����԰塣\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

