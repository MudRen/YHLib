inherit ROOM;

void create()
{
        set("short", "ѩ��");
        set("long", @LONG
������һƬ��ãã��ѩ�أ�һ���������߼ʡ�����һ����ӰҲû�У���
��Ļ�ѩ������������֨�����������������һ���¶��Ľ�ӡ������ı���
��Х��������������ʹ��������̫����������ߣ��Ե���ô�԰ס�
LONG );
        set("exits", ([
                "west"       : __DIR__"dongcheng",
                "northeast"  : __DIR__"xuedi2",
                "northwest"  : __DIR__"songlin1",
        ]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
        set("outdoors", "guanwai");
        setup();
}
