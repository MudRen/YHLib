inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�������̼ұ��ĺ�Ժ����Ժ��������������ȫ������ɳʯ
�������ϱ���һ����ľ�����ȣ�ͨ���������ڡ���߲�ʱ������
���˱ǵķ����㣬ԭ�������ǳ������ڡ�
LONG);
	set("exits", ([
		"north"  : __DIR__"shang_lianwun",
		"south"  : __DIR__"shang_zoulang2",
		"east"  : __DIR__"shang_huating",
		"west"  : __DIR__"shang_chufang",
	]));
        set("objects", ([
                CLASS_D("shang") + "/tai" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
