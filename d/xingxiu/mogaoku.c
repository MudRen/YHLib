inherit ROOM;

void create()
{
        set("short", "Ī�߿�");
        set("long", @LONG
����ǽ���ϻ�����������صĻ��棬����Ů���죬����
�������á����л��кܶ����;��顣�㱻��Щ�������Ļ�֮
�������ˡ�
LONG );
        set("exits", ([ 
             	"out" : __DIR__"yueerquan",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

