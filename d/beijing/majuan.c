inherit ROOM;

void create ()
{
  	set ("short", "���");
  	set ("long", @LONG
������Զ�ھ���ĵ���ǣ����깩Ӧ���ʲ��ϡ�����޵������쳣������
����ר���չˡ��������ƥι�����㣬ϴˢ�ø�Ǭ������ƽʱ�ھ����������
������ƥ���������﹩Ӧ�ġ�����жѷ������Ѳ��ϣ�������һ����ۡ����
����ǰ����һ�����������ױ���д�ĸ�ʾ(gaoshi)��
LONG);

  	set("exits", ([
  		"west" : __DIR__"front_yard",
	]));

  	set("objects", ([
                "/clone/horse/zaohongma": 1,
                "/clone/horse/huangbiaoma": 1,
                "/clone/horse/ziliuma": 1,
		__DIR__"npc/matong": 1,
        ]));
        set("item_desc", ([
                "gaoshi": @TEXT

��Զ�ھֵ���ʦ����������������³��С�

 ���ݳ�:  rideyz    ���ݳ�:  ridesz
 ���ݳ�:  ridehz    ���ݳ�:  ridefz
 �����:  ridedl    ������:  ridexy
 ���ǳ�:  rideyd    ������:  rideyl
 ��ɽ��:  ridefs    ����ɽ:  rideem

TEXT]));
  	setup();
        replace_program(ROOM);
}