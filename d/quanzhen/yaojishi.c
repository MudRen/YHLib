inherit ROOM;

void create()
{
        set("short", "ҩ����");
        set("long", @LONG
������ȫ�����ҩ����ҩ�ĵط�����䷿�䱾���ܴ�ֻ
�Ǳ�ǰ�����Ҷѷŵ�ҩ��ҩ�伷���Ե�С���ˡ�ҩ���Ѿ��ܳ�
���ˣ����������Ϻõ��Ϻ�����ľ���ɵģ���˵������ľ����
�ɵĹ����������ض��������������
LONG);
        set("sleep_room",1);
        set("exits", ([
                "east" : __DIR__"xianzhentang",
        ]));

        set("objects", ([
                __DIR__"npc/zhangyao" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
