inherit ROOM;

void create()
{
        set("short",  "����" );
        set("long", @LONG
������������Ķ����ţ�����������ɫ�˳�������������
�ͣ����������ģ�Ҳ����Щ������ʿ�����߿��Կ����̼��ʡ�
LONG);
        set("outdoors", "kunming");

        set("exits", ([
                "west" : __DIR__"bijifang", 
                "east"  :__DIR__"qingshilu2",
        ]));
        set("objects", ([
                "/d/beijing/npc/ducha" : 1,
                "/d/city/npc/bing" : 4,
        ]));
        setup();
        replace_program(ROOM);
}