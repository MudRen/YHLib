inherit ROOM;

void create ()
{
  	set ("short", "������");
  	set ("long", @LONG
������һ�������� (jia)��ʮ�˰����������ȫ�������Ա߹�����ʮ����
������Ŀ��ף���������սѥ����Ա�һλ��ʦ����Ŀ���񣬿������Ը���
Ҫ(yao)һ���¼׺�һ�����ֵı�����
LONG);

        set("item_desc", ([
                "jia" : "����һ�������ܣ���������˼�(body)����(helmet)��ѥ(feet)�����ľ�(waist)�Լ����������\n",
        ]));

  	set("exits", ([
  		"west" : __DIR__"front_yard2",
	]));

  	set("objects", ([
        	__DIR__"npc/qianzhenglun": 1,
        ]));

  	setup();
        replace_program(ROOM);
}
