inherit ROOM;

void create()
{
        set("short", "�������Ժ");
        set("long", @LONG
����һ���������ͥԺ���ſڴ���������Ͷ��Ժ�����
�˾��ú����졣Ժ�Ӷ����ǿ��������߾���С���֡�
LONG);
        set("exits", ([ 
            	"west" : __DIR__"beijiang",
            	"east" : __DIR__"house1",
        ]));
        set("objects", ([
                __DIR__"npc/kid": 1,
        ]));
        set("outdoors", "xingxiu");
        setup();
}
