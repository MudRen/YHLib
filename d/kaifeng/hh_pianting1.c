inherit ROOM;

void create()
{
        set("short", "ƫ��");
        set("long", @LONG
ƫ�����õ���Ϊ���ţ�˿��û�������ϵ��������ա�һ��
��ľ���������и���񣬹�����˸�ʽ�������顣ǽ�Ϲ��ż�
���ֻ�������������ʱ�������ֿ��Ե��鷿�á�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"east" : __DIR__"hh_zoulang2",
	]));
        setup();
        replace_program(ROOM);
}
