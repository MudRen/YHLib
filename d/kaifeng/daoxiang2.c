inherit ROOM;

void create()
{
        set("short", "����Ӷ�¥");
        set("long", @LONG
�ϴ�һ���������໥�����������ʮ���С�䡣��������
��С�����Ų��������ߣ������������Ļ����������̵�����
�ߵ�λ�á��ߺȾƱ߿�������ķ����־�������һ�֡�
LONG);
        set("objects", ([
  		__DIR__"npc/gaoyanei" : 1,
  		__DIR__"npc/luyuhou" : 1,
	]));

        set("no_clean_up", 0);
        set("exits", ([
  		"down" : __DIR__"daoxiang",
	]));

        setup();
        replace_program(ROOM);
}
