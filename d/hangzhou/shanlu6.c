inherit BUILD_ROOM;

void create()
{
        set("short", "���ɽ·");
        set("long", @LONG
ɽ·��᫣��������ӡ�������ľ�Դ䣬����ï�ܡ�ɽ·��
��һɽ������˵������ʱ�ᴫ���������������ϻ�������Ȼ��
�ˣ���ɫ������ˣ����ܲ�����������ס֮�⣿��������ɽ��
·������ɽ�㵽��ɽ�ס�
LONG);
        set("exits", ([
            	"eastup"  : __DIR__"yuhuangsd",
            	"westdown": __DIR__"yuhuangshan",
        ]));
        set("objects", ([
            	"/clone/quarry/laohu" : 1,
        ]));
        set("outdoors", "hangzhou");
        set("max_room", 4);
        setup();
        replace_program(ROOM);
}
