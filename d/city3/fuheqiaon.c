inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG
�����ǳɶ������⸮���š��ɶ����Ǵ����׸���ȴ���տ�
�أ�һ���з������ɶ�ƽԭ����ʹ��������ˮ�ǣ�Ҳ��ֻ�е�
��Է��ȱ���ѡ���ˡ�
LONG);
	set("outdoors", "chengdu");
	set("exits", ([
            	"north"  : "/d/qingcheng/qcroad1",
            	"south"  : __DIR__"northgate",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

