inherit ROOM;

void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
����һ����ʯ�����Сɽ�ڣ��򶫱���ͨ��ƽ���ݵ�С·��
��˵ǰ��������Ұ�޳�û�����ɾ�����
LONG );
        set("outdoors", "heimuya");
        set("exits", ([
            	"north" : __DIR__"road2",
            	"south" : __DIR__"road4",
            	"west"  : __DIR__"linjxd1",
            	"east"  : __DIR__"tianroad1",
        ]));
        set("objects", ([
           	__DIR__"npc/laozhe" : 1 ,
        ]));
        setup();
        replace_program(ROOM);
}
