inherit BULLETIN_BOARD;

void create()
{
        set_name("��Զ�ھ����԰�", ({ "board" }) );
        set("location", "/d/beijing/zhengting");
        set("board_id", "zhenyuan_b");
        set("long", "����һ���������ŵ��ӽ��������԰塣\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

