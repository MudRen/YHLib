inherit ROOM;

void create()
{
        set("short", "���޺�");
        set("long", @LONG
���������޺��ľ�ͷ����Ϊ������Ұ���û������������
���ӳ����ڴ˿����⴮�ԡ����򲻵�Ұ��ʱ�����Ǿ���ɽ����
�˵���
LONG);
        set("exits", ([
             "southeast" : __DIR__"xxh3",
             "southwest" : __DIR__"xxh4",
        ]));
        set("objects", ([
                __DIR__"npc/boshou"  : 1,
                __DIR__"obj/yangrou" : 2
        ]));
        set("outdoors", "xingxiu");
        setup();
        replace_program(ROOM);
}

