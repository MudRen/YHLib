inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ�������ӣ����ζ��ܾ��ˣ����ҿ��ó������Լ�
���ô���ƴ�������ģ��������õúܸɾ���ǽ����б����֧
�Բ棬Ҳ����ҵ����˻��Ǹ����Ը��֡�
LONG);
        set("exits", ([
                "southeast" : __DIR__"guchang",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
