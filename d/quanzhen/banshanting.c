inherit ROOM;

void create()
{
        set("short", "��ɽͤ");
        set("long", @LONG
�����ǰ�ɽ����һ��С��ͤ���ο�����ɽ�������ˣ���ת
���䵽��������һ����ЪһЪ�š������￴��ȥ���պÿ��Կ�
��������ķ嶥��
LONG);
        set("outdoors", "quanzhen");
        set("exits", ([
                "southdown" : __DIR__"shijie5",
        ]));

        set("objects",([
                __DIR__"npc/youke" : 2,
                "/clone/npc/walker" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
