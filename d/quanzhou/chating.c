inherit ROOM;

void create()
{
        set("short", "��ͤ");
        set("long", @LONG
����һ��·�ߵ�С��ͤ����ɽ·���˳��ڴ˴�ЪЪ�š�ͤ
�����м������Ӻͼ�֧���ʡ���Χ��һƬ���֡�
LONG );
        set("exits", ([
                "west" : __DIR__"qzroad4",
        ]));
        set("objects", ([
                CLASS_D("riyue") + "/xiang" : 1,
        ]));
        set("outdoors", "quanzhou");
        setup();
        replace_program(ROOM);
}

