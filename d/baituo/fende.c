inherit ROOM;

void create()
{
        set("short", "�ص�");
        set("long", @LONG
������һƬ������ɭ�Ļķصأ�ʱ��ʱ����������ѻ�Ľ�
������λ���긾Ů���������ɥ����������ͣ��
LONG);
        set("outdoors", "baituo");

        set("exits", ([
                "southwest" : __DIR__"xiaolu1",
        ]));

        set("objects" , ([
                __DIR__"npc/guafu" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
