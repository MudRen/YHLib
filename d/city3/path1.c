inherit ROOM;

void create()
{
	set("short", "佻�Ϫ");
	set("long", @LONG
������佻�Ϫ����С·�ϣ�佻�Ϫˮ��Ө��͸����������
ԶԶ�����ŵ�ˮ�������㡣���˯��ɢ����Ϫ��������ˮ��Ʈ
���������ĸ�Ƽ����Ƽ���в����޺��������ȥ��Ϫ��С·
��Ϫ���������ƣ�����û�㣬��Ʈ�ƺ���ʹ�˲�����������
��ν���д����ϲ����ۡ�
LONG);
        set("outdoors", "chengdu");
	set("exits", ([
		"north"  : __DIR__"path2",
		"east"   : __DIR__"nanheqiaow",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
