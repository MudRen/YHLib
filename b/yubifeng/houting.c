// /guanwai/houting.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @long
������ׯ�����÷���Ϣ�ĵط����ĽǸ�����һ���̿��һ�Ű�������
�У���Χ��ɨ�����Ǹɾ����ܼ����ں������ǷԸ���ʲô��
long );
        set("exits", ([
                "south"    : __DIR__"houyuan",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "guanwai");
        setup();
        replace_program(ROOM);
}
