inherit ROOM;

void create()
{
        set("short", "����С·");
        set("long", @LONG
����ʥ���ߵ�С·���������ģ��װ��ƶ��ں���Ư�ƣ���
�����١�����������һЩ��������Ĳ�֪���İ�����
LONG);
        set("outdoors", "xuedao");
        set("exits", ([
                "north" : __DIR__"hubian4",
                "west"  : __DIR__"hubian2",
        ]));
        setup();
        replace_program(ROOM);
}
