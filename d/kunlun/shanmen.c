inherit ROOM;

void create()
{
	set("short", "������ɽ��");
        set("long", @long
��һ·���������ܴ���ɳ֮�࣬������ľ������������
ʱ������֦Ҷ�д�����������·�߲ݴ�ż��Ҳ�ܷ���һЩ����
��Ұ��������������������컨��ʮ��ïʢ��������û�뵽
��ɽ��ȴ��������ڣ������Ϊһ��ǰ����һ��ɽ�ţ�д��
�������������֡�
long);
	set("exits",([
		"eastup" : __DIR__"shanlu01",
		"southdown" : __DIR__"klshanlu",
	]));

	set("objects",([
                CLASS_D("kunlun") + "/jiangtao" : 1,
                __DIR__"npc/kl-dizi1" :  1,
                __DIR__"npc/kl-dizi2" :  1,
        ]));

	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}
