inherit ROOM;

void create()
{
	set ("short", "Ұ����");
	set ("long", @LONG
�ԴӲ���ǰ�������г���Ұ��֮����Ƭ���־���������
�⾳�ڣ�̸��ɫ�ߡ�ֻ��Ϊ�������ȵ����ӻ����ֱߴ�ЩҰ��
�������ո�ǿ��ͼ��·����Ҳ�Ӵ˹��������˵ر��ǻ�ɽ��
LONG);

	set("outdoors", "kaifeng");
	set("exits", ([
        	"northeast" : __DIR__"dadao2",
        	"west" : "/d/huashan/path1",
	]));
        set("objects", ([
                "/clone/quarry/zhu" : 2,
                "/clone/quarry/zhu2" : 2,
        ]));
	setup();
	replace_program(ROOM);
}
