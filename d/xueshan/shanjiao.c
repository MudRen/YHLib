inherit ROOM;

void create()
{
        set("short", "ѩɽɽ��");
        set("long", @LONG
������ɽ���µ�һƬƽ�أ�ɽ�ϲ�Զ����������ѩӳ����
��һ��Ƭ��ǽ���ߴ�������Զ��������ѩɽ�¡�
LONG);
        set("outdoors", "xuedao");
        set("exits", ([
                "westup" : "/d/xuedao/nroad7",
                "south"  : __DIR__"hubian4",
        ]));
        setup();
        replace_program(ROOM);
}
