inherit ROOM;

void create()
{
        set("short", "��·");
        set("long", @LONG
����һ�������۵���·������ȴҲ��խ����ɢ�ĸ�����¶
���������̵�Ƶ�����������Ӵ���������ԭ�ıؾ�֮·��
LONG);
        set("outdoors", "xuedao");
        set("exits", ([
                "east" : __DIR__"caoyuan",
                "west" : __DIR__"tulu2",
        ]));
        setup();
        replace_program(ROOM);
}
