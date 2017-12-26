#include "log.h"

void InitLog() {
	typedef sinks::synchronous_sink<sinks::text_file_backend> TextSink;

	// init sink1  
	auto backend1 = boost::make_shared<sinks::text_file_backend>(
		keywords::file_name = "ratel.log.%Y-%m-%d.%N.log",
		keywords::rotation_size = 10 * 1024 * 1024,
		keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
		keywords::min_free_space = 30 * 1024 * 1024);
	auto sink1 = boost::make_shared<TextSink>(backend1);
	sink1->set_formatter(
		expr::format("[%1%]<%2%>(%3%): %4%")
		% expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d %H:%M:%S")
		% expr::attr<sign_severity_level>("Severity")
		% expr::attr<attrs::current_thread_id::value_type >("ThreadID")
		% expr::smessage
		);
	sink1->set_filter(expr::attr<sign_severity_level>("Severity") >= warning);
	logging::core::get()->add_sink(sink1);

	// init sink2  
	//boost::shared_ptr<sinks::text_file_backend> backend2 = boost::make_shared<sinks::text_file_backend>(
	//	keywords::file_name = "sign_%Y-%m-%d.csv",
	//	keywords::rotation_size = 100 * 1024 * 1024,
	//	keywords::time_based_rotation = sinks::file::rotation_at_time_point(boost::gregorian::greg_day(1), 0, 0, 0),
	//	keywords::min_free_space = 30 * 1024 * 1024);
	//backend2->auto_flush(true);
	//boost::shared_ptr<TextSink> sink2(new TextSink(backend2));
	//sink2->set_formatter(
	//	expr::format("%1%,%2%")
	//	% expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d %H:%M:%S")
	//	% expr::smessage
	//	);
	//sink2->set_filter(expr::attr<sign_severity_level>("Severity") == report);
	//logging::core::get()->add_sink(sink2);
	logging::add_common_attributes();
	logging::core::get()->add_global_attribute("ThreadID", attrs::current_thread_id());
}