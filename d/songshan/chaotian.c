inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����˫���жϣ���Ȼ����һ���Ż���ֻ������ӶϾ�����
�����������죬����������������������ǳ������ˡ�
LONG );
	set("exits", ([
		"northup"   : __DIR__"shandao6",
		"southdown" : __DIR__"shandao5",
	]));
	set("outdoors", "songshan");
        set("objects", ([
                CLASS_D("songshan") + "/fei" : 1,
        ])); 
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

