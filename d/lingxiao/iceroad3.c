inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������������߶��ܰ����������Ǳ����������������ǵļ�
�������߹�ȥ�����������ǵĸ���֮��----ѩɽ�ɵ�����������
�ˣ�������ؽ��ܣ��Ĵ������������ӡ�
LONG);
        set("outdoors", "lingxiao");
        set("exits", ([
            	"south" : __DIR__"iceroad2",
            	"north" : __DIR__"meiroad1",
            	"west"  : __DIR__"car",
            	"east"  : __DIR__"jianyuting",
        ]));
        set("objects", ([
                __DIR__"npc/dizi" : 2,
        ]));
        setup();
        replace_program(ROOM);
}

