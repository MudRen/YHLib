inherit ROOM;

void create()
{
        set("short", "��ի��");
        set("long", @LONG
���������еĴ�Сɮ���ò͵ĵط�����Ȼ���ɵ���ի��ר
�������͹�ȥ�ģ�ƽʱ����µ�ɮ�����ӳԷ��������ǳ�����
Ҳ������ʣ�µ���ի������˳ԡ���������ʮ��Ҳ������Щի
ϯ���ʩ�����߹ٸ�����Ʒ����������ի����ɮ������æ�ġ�
LONG
        );
        set("exits", ([
  		"north" : __DIR__"chufang2",
  		"west" : __DIR__"zhongyuan",
	]));

        set("no_clean_up", 0);
        set("objects", ([
  		__DIR__"npc/liucaizhu" : 1,
  		__DIR__"npc/kong" : 1,
	]));

        setup();
        replace_program(ROOM);
}
